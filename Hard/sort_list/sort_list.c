/*
	Fichiers à rendre : sort_list.c
	Fonctions Autorisées :

	Écrire la fonction suivante :

	t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

	Cette fonction doit trier la liste passée en premier paramètre, en utilisant le pointeur
	sur fonction cmp pour déterminer l’ordre à appliquer, et renvoyer un pointeur vers le
	premier élément de la liste triée.

	Les doublons doivent être préservés.

	Les entrées seront toujours cohérentes.

	Vous devez utiliser le type t_list décrit dans le fichier list.h qui vous est fourni.

	Vous devrez inclure (#include "list.h") ce fichier, mais ne pas le rendre. Nous utilise-
	rons le notre pour compiler votre exercice.

	Les fonctions passées en tant que cmp renverront toujours une valeur différente de 0
	si a et b sont dans le bon ordre, dans le cas contraire elles renverront 0.

	Par exemple, la fonction suivante utilisée en tant que cmp devra permettre de trier la
	liste par ordre croissant :


	int croissant(int a, int b)
	{
		return (a <= b);
	}
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct 		s_list
{
	int 			data;
	struct s_list  	*next;
}              		t_list; 

t_list		*sort_list(t_list *lst, int (*cmp)(int, int))
{

	t_list *count;
	t_list *current;
	int l;
	int temp;

	count = lst;
	while(count)
	{
		count = count->next;
		l++;
	}
	current = lst;
	while (l)
	{
		while(current->next)
		{
			if ((cmp)(current->data, current->next->data))
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
			}
			current = current->next;
		}
		l--;
		current = lst;
	}
	return (current);	
}

void print_list(t_list *head)
{
	t_list *current = head;

	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}

void push(t_list *head, int val)
{
	t_list *current = head;

	while (current->next != NULL)
		current = current->next;

	current->next = malloc(sizeof(t_list));
	current->next->data = val;
	current->next->next = NULL;
}

int croissant(int a, int b)
{
	return(a <= b);
}

int main(void)
{
	int (*cmp)(int, int);
	t_list *head = NULL;

	cmp = &croissant;
	head = malloc(sizeof(t_list));
	head->data = 40;
	head->next = NULL;
	push(head, 5);
	push(head, 10);
	push(head, 1);
	push(head, 3);
	push(head, 8);
	head = sort_list(head, cmp);
	print_list(head);
}
