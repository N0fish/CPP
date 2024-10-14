// #include <iostream>

// int	main()
// {
// 	int a;
// 	int b;

// 	if (!(std::cin >> a))
// 		return (std::cerr << "Ошибка a\n" << std::endl, 1);
// 	if(!(std::cin >> b))
// 		return (std::cerr << "error b\n" << std::endl, 1);

// 	if (a >= b)
// 		return (std::cerr << "Errror range\n" << std::endl, 1);

//     for (int i = a; i <= b; ++i)
//         if (i % 3 == 0)
//             std::cout << i << " ";

// 	std::cout << std::endl;
// 	return (0);
// }

#include <iostream>

enum {max_size_ar=20};

int main()
{
    int		data[max_size_ar];
	int		count = 0;
	char	ch;

    for (int i = 0; i < max_size_ar; i++)
	{
        if (std::cin >> data[count])
		{
            count++;
			std::cin >> ch;
			if (std::cin.fail())
				break ;
		}
		else
            break ;
    }
	for (int i = 0; i < count; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return (0);
}

// #include <iostream>

// enum {max_size_name=50};

// struct THING {
//     unsigned int	id;
//     char			name[max_size_name];
//     double			weight;
//     unsigned int	price;
// };

// int main()
// {
// 	THING box;

// 	std::cin >> box.id >> box.name >> box.weight >> box.price;

//  	std::cout	<< box.name << " "
// 				<< box.id << ": "
// 				<< box.weight << ", "
// 				<< box.price
// 				<< std::endl;

//     // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
//     return (0);
// }

// #include <iostream>
// #include <cmath>

// double	triangle_sq(int a, int b, int c)
// {
// 	double	p;

// 	p = (a + b + c) / 2.0;
// 	return (std::sqrt(p * (p - a) * (p - b) * (p - c)));
// }

// int	main(void)
// {
// 	int		a;
// 	int		b;
// 	int		c;
// 	double	area;

// 	std::cin >> a >> b >> c;

// 	area = triangle_sq(a, b, c);

// 	std::cout.precision(2);
// 	std::cout << std::fixed << area << std::endl;

//     return (0);
// }