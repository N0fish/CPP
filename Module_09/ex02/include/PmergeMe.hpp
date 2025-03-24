/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:09:23 by algultse          #+#    #+#             */
/*   Updated: 2025/03/24 23:53:09 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
# define PMERGE_HPP

# include "Colors.hpp"

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void runSort(int argc, char **argv);

	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		std::vector<int>	_vecSorted;
		std::deque<int>		_deqSorted;

		clock_t				_vectorTime;
		clock_t				_dequeTime;

		void	parseArguments(int argc, char **argv);
		bool	isValidNumber(const std::string &str) const;

		void	printBefore() const;
		void	printAfter() const;

		void	sortVector();
		void	sortDeque();

		void	buildPairs(std::vector<std::pair<int, int> > &pairs, const std::vector<int> &input);
		void	buildPairs(std::deque<std::pair<int, int> > &pairs, const std::deque<int> &input);

		std::vector<int>	extractMain(const std::vector<std::pair<int, int> > &pairs);
		std::deque<int>		extractMain(const std::deque<std::pair<int, int> > &pairs);

		std::vector<int>	extractPending(const std::vector<std::pair<int, int> > &pairs);
		std::deque<int>		extractPending(const std::deque<std::pair<int, int> > &pairs);

		void	insertPending(std::vector<int> &main, const std::vector<int> &pending, const std::vector<size_t> &indices);
		void	insertPending(std::deque<int> &main, const std::deque<int> &pending, const std::vector<size_t> &indices);

		std::vector<size_t>	createJacobsthalIndices(size_t size) const;
		int					getJacobsthal(size_t n) const;
};

#endif