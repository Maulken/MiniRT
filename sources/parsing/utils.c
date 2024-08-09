

#include "../../includes/minirt.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	str = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1)
			* sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
    {
		str[i++] = s2[j++];
    }
	str[i] = '\0';
    free(s1);
    free(s2);
	return (str);
}


void printf_row(char **row)
{
    int i;
    int j;

    j = 0;
    
    while(row[j])
    {
        i=0;
        while(row[j][i])
            printf("%c",row[j][i++]);
        j++;
    }
    printf("\n");

}