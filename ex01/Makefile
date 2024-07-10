NAME		:= phonebook

SRCDIR		:= .
OBJDIR		:= obj
INCDIR		:= .

SRCS		:= \
	$(SRCDIR)/main.cpp \
	$(SRCDIR)/Contact.cpp \
	$(SRCDIR)/PhoneBook.cpp \

OBJS		:= $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.obj,$(SRCS))
INCS		:= \
	$(INCDIR)/Contact.hpp \
	$(INCDIR)/PhoneBook.hpp \

CXX			:= c++
INCLUDES	:= -I$(INCDIR)
CXXFLAGS	:= -O3 -Wall -Werror -Wextra -std=c++98 $(INCLUDES)
LDFLAGS		:=

RM			:= rm
RMFLAGS		:= -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

$(OBJDIR)/%.obj: $(SRCDIR)/%.cpp $(INCS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(RMFLAGS) $(OBJDIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all
