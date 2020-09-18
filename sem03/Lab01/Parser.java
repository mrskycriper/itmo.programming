package com.mrskycriper;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Vector;

public class Parser
{
	static Vector<Node> Process(String FileIn) throws FileNotFoundException
	{
		if (FileIn.length() < 4)
		{
			return null;
		}
		Vector<Node> result = new Vector<>();
		String buffer;
		buffer = FileIn.substring(FileIn.length() - 4);
		if (!buffer.equals(".ini"))
		{
			return null;
		}

		Scanner sc = new Scanner(new File(FileIn));

		String bufferSectionName;
		String[] splittedComments;
		String[] splittedBuffer;
		while (sc.hasNext())
		{
			buffer = sc.nextLine();

			while (buffer.equals("") || buffer.charAt(0) == ';')
			{
				buffer = sc.nextLine();
			}
			if (buffer.charAt(0) == '[')
			{
				bufferSectionName = buffer.substring(1, buffer.length() - 1);
				while (!bufferSectionName.matches("[A-Za-z_0-9]+"))
				{
					System.err.println(buffer + " is not a valid section name, skipping");
					while (sc.hasNext())
					{
						buffer = sc.nextLine();
						if (!buffer.equals("") && buffer.charAt(0) == '[')
						{
							bufferSectionName = buffer.substring(1, buffer.length() - 1);
							break;
						}
					}
					if (!sc.hasNext())
					{
						return result;
					}
				}
				buffer = sc.nextLine();
				while (!buffer.isEmpty())
				{
					while (buffer.charAt(0) == ';')
					{
						buffer = sc.nextLine();
					}
					splittedComments = buffer.split(";");
					splittedBuffer = splittedComments[0].split("=");
					splittedBuffer[0] = splittedBuffer[0].trim();
					if (!splittedBuffer[0].matches("[A-Za-z_0-9]+"))
					{
						System.err.println(splittedBuffer[0] + " is not a valid variable name, skipping");
					}
					else
					{
						splittedBuffer[1] = splittedBuffer[1].trim();
						Node bufferNode = new Node(bufferSectionName, splittedBuffer[0], splittedBuffer[1]);
						result.add(bufferNode);
					}
					if (!sc.hasNext())
					{
						break;
					}
					buffer = sc.nextLine();
				}

			}
		}
		return result;
	}

	static boolean isNumber(String Value)
	{
		try
		{
			Double.parseDouble(Value);
		}
		catch (Exception isNotDouble)
		{
			return false;
		}
		return true;
	}

	static boolean isInt(String Value)
	{
		try
		{
			Integer.parseInt(Value);
			return true;
		}
		catch (Exception isNotInt)
		{
			return false;
		}
	}
}
