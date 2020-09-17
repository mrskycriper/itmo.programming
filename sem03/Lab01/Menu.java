package com.mrskycriper;

public class Menu
{
	static void showInfo(String FileIn, int NamesCount)
	{
		System.out.println("Parsing " + FileIn);
		System.out.println(NamesCount + " values found.");
	}

	static void showActions()
	{
		System.out.println("+----------------------------------------------------------------------------------------------------------------+");
		System.out.println("|Available actions:                                                                                              |");
		System.out.println("|1) Search by section name.                                                                                      |");
		System.out.println("|2) Search by combination of section name and variable name.                                                     |");
		System.out.println("|3) Search by combination of section name, variable name and value type. Can Convert Int to Double and backwards.|");
		System.out.println("|4) Select new .ini file                                                                                         |");
		System.out.println("|5) Exit                                                                                                         |");
		System.out.println("|Enter corresponding action number bellow to continue                                                            |");
		System.out.println("+----------------------------------------------------------------------------------------------------------------+");
	}

	static void showFileSelect()
	{
		System.out.println("Enter your request bellow using this pattern: FILE_NAME");
	}

	static void showSectionOnlySearch()
	{
		System.out.println("Enter your request bellow using this pattern: SECTION_NAME");
	}

	static void showSectionAndNameSearch()
	{
		System.out.println("Enter your request bellow using this pattern: SECTION_NAME VARIABLE_NAME");
	}

	static void showFullSearch()
	{
		System.out.println("Enter your request bellow using this pattern: SECTION_NAME VARIABLE_NAME VALUE_TYPE " +
				"\nValue type can be String, Integer or Double");
	}
}
