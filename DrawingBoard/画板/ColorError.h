#pragma once
#include <iostream>
#include <exception>
class ColorError :public std::exception{
public:
		ColorError() = default;
		const char* what()const noexcept(true) override;
};

