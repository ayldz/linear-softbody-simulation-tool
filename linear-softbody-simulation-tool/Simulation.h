#pragma once
#include "Mass.h"
#include "Lsst.h"

class Simulation
{
public:
	int m_numOfMasses;
	std::vector<Mass*> m_masses{};

	Simulation(int numOfMasses, float m)
	{
		this->m_numOfMasses = numOfMasses;
		

		for (size_t i = 0; i < m_numOfMasses; ++i)
		{
			m_masses.push_back(new Mass(m));
		}

	}

	virtual void Release()
	{
		for (size_t i = 0; i < m_numOfMasses; i++)
		{
			delete m_masses[i];
			m_masses[i] = nullptr;
		}
	}

	Mass* GetMass(int index)
	{
		if (index < 0 || index >= m_numOfMasses)
		{
			return nullptr;
		}

		return m_masses[index];
	}

	virtual void Init() 
	{
		for (size_t i = 0; i < m_numOfMasses; i++)
		{
			m_masses[i]->Init();
		}
	}

	virtual void Solve() {};

	virtual void Simulate(float dt) 
	{
		for (size_t i = 0; i < m_numOfMasses; i++)
		{
			m_masses[i]->Simulate(dt);
		}
	}

	virtual void Operate(float dt) 
	{
		Init();
		Solve();
		Simulate(dt);
	}
};

