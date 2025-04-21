/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-goff <tle-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:25:47 by tle-goff          #+#    #+#             */
/*   Updated: 2025/04/17 13:07:52 by tle-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << "PmergeMe has create !" << std::endl;
}

PmergeMe::~PmergeMe() {
	std::cout << "PmergeMe has delete !" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &src) {
	if (this != &src) {
	}
	return (*this);
}

std::list<int> mergeLists(std::list<int>& list1, std::list<int>& list2) {
	std::list<int> merged;
	std::list<int>::iterator it1 = list1.begin();
	std::list<int>::iterator it2 = list2.begin();

	while (it1 != list1.end() && it2 != list2.end()) {
		if (*it1 <= *it2) {
			merged.push_back(*it1);
			++it1;
		} else {
			merged.push_back(*it2);
			++it2;
		}
	}

	while (it1 != list1.end()) {
		merged.push_back(*it1);
		++it1;
	}

	while (it2 != list2.end()) {
		merged.push_back(*it2);
		++it2;
	}

	return (merged);
}

void	fordJohnsonSort2(std::list<int>& list) {
	int n = list.size();

	if (n < 2)
		return;
	std::list<std::list<int> > groups;
	std::list<int>::iterator it = list.begin();
	for (int i = 0; i < n; i++) {
		std::list<int> single_elem_list;
		single_elem_list.push_back(*it);
		groups.push_back(single_elem_list);
		++it;
	}
	while (groups.size() > 1) {
		std::list<std::list<int> > new_groups;
	std::list<std::list<int> >::iterator group_it = groups.begin();
		while (group_it != groups.end()) {
			std::list<std::list<int> >::iterator next_group_it = group_it;
			++next_group_it;
			if (next_group_it != groups.end()) {
				std::list<int> merged = mergeLists(*group_it, *next_group_it);
				new_groups.push_back(merged);
				++group_it;
			} else
				new_groups.push_back(*group_it);
			++group_it;
		}
		groups = new_groups;
	}
	list = groups.front();
}

void insertionSort(std::deque<int>& dq, std::deque<int>::size_type left, std::deque<int>::size_type right) {
	for (std::deque<int>::size_type i = left + 1; i <= right; ++i) {
		int key = dq[i];
		int j = static_cast<int>(i) - 1;
		while (j >= static_cast<int>(left) && dq[j] > key) {
			dq[j + 1] = dq[j];
			--j;
		}
		dq[j + 1] = key;
	}
}

void merge(std::deque<int>& dq, std::deque<int>::size_type left, std::deque<int>::size_type mid, std::deque<int>::size_type right) {
	std::deque<int> leftDeque(dq.begin() + left, dq.begin() + mid + 1);
	std::deque<int> rightDeque(dq.begin() + mid + 1, dq.begin() + right + 1);
	std::deque<int>::size_type i = 0, j = 0, k = left;
	while (i < leftDeque.size() && j < rightDeque.size()) {
		if (leftDeque[i] <= rightDeque[j]) {
			dq[k++] = leftDeque[i++];
		} else {
			dq[k++] = rightDeque[j++];
		}
	}
	while (i < leftDeque.size()) {
		dq[k++] = leftDeque[i++];
	}
	while (j < rightDeque.size()) {
		dq[k++] = rightDeque[j++];
	}
}

void fordJohnsonSort(std::deque<int>& dq) {
	std::deque<int>::size_type n = dq.size();
	for (std::deque<int>::size_type i = 0; i < n; i += 2) {
		insertionSort(dq, i, std::min(i + 1, n - 1));
	}
	for (std::deque<int>::size_type size = 2; size < n; size *= 2) {
		for (std::deque<int>::size_type left = 0; left < n; left += size * 2) {
			std::deque<int>::size_type mid = std::min(left + size - 1, n - 1);
			std::deque<int>::size_type right = std::min(left + size * 2 - 1, n - 1);
			merge(dq, left, mid, right);
		}
	}
}

int	checkNumber(char *str) {
	int	i = 0;
	while (str[i]) {
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	PmergeMe::setDeque(char **argv) {
	int i = 1;
	std::deque<int> list;
	int n;
	while (argv[i]) {
		n = std::atoi(argv[i]);
		if (n < 0)
			return (std::cout << "Error" << std::endl, 1);
		list.push_back(n);
		i++;
	}

	std::cout << "Before: ";
	for (std::size_t i = 0; i < list.size(); i++) {
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;

	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	fordJohnsonSort(list);
	clock_gettime(CLOCK_MONOTONIC, &end);

	std::cout << "After: ";
	for (std::size_t i = 0; i < list.size(); i++) {
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;

	double start_ns = start.tv_sec * 1e9 + start.tv_nsec;
	double end_ns = end.tv_sec * 1e9 + end.tv_nsec;
	double duration_us = (end_ns - start_ns) / 1000.0;

	std::cout << std::fixed << std::setprecision(5) << "Time to process the elements with std::deque: " << duration_us << " us" << std::endl;
	return 0;
}

int	PmergeMe::setList(char **argv) {
	int i = 1;
	std::list<int> list;
	int n;

	while (argv[i]) {
		n = std::atoi(argv[i]);
		if (n < 0) {
			std::cout << "Error: negative number not allowed" << std::endl;
			return 1;
		}
		list.push_back(n);
		i++;
	}

	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	fordJohnsonSort2(list);
	clock_gettime(CLOCK_MONOTONIC, &end);

	double start_ns = start.tv_sec * 1e9 + start.tv_nsec;
	double end_ns = end.tv_sec * 1e9 + end.tv_nsec;
	double duration_us = (end_ns - start_ns) / 1000.0;

	std::cout << std::fixed << std::setprecision(5) << "Time to process the elements with std::list: " << duration_us << " us" << std::endl;
	return 0;
}
