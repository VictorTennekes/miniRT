/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 08:35:56 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/08 14:42:12 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int	ft_numlen(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_allocmem(int len)
{
	char *res;

	res = (char*)malloc(len);
	if (res == NULL)
		return (NULL);
	res[len - 1] = '\0';
	return (res);
}

static char	*ft_exception(int n)
{
	char	*res;

	res = (char *)malloc((n == 0) ? 2 : 13);
	if (res == NULL)
		return (NULL);
	if (n == 0)
		ft_strlcpy(res, "0", 2);
	else
		ft_strlcpy(res, "-2147483648", 12);
	return (res);
}

static char	*ft_solve(int tmp, int n, int num_len, char *res)
{
	int i;

	i = -1;
	while (i + 1 < tmp)
	{
		i++;
		res[num_len - i - 1] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		num_len;
	int		sign;
	int		tmp;

	sign = n < 0;
	num_len = ft_numlen(n);
	res = ft_allocmem(num_len + 1);
	if (res == NULL)
		return (NULL);
	if (n == -2147483648 || n == 0)
		return (ft_exception(n));
	if (sign)
	{
		*res = '-';
		n *= -1;
	}
	tmp = num_len - sign;
	ft_solve(tmp, n, num_len, res);
	return (res);
}
