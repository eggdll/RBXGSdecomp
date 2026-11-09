#pragma once
#include "util/debug.h"

namespace RBX{
	class KernelIndex
	{
		public:
			int kernelIndex;
			KernelIndex():kernelIndex(-1) {}
			~KernelIndex() {RBXASSERT(kernelIndex == -1);}
			//virtual void fakeFunc(){};

	};
}