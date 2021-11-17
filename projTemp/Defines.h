#pragma once
#include "cryptoTools/Common/Defines.h"
#include "cryptoTools/Common/Matrix.h"
#include "cryptoTools/Common/BitVector.h"

namespace volePSI
{

	using u64 = oc::u64;
	using u32 = oc::u32;
	using u16 = oc::u16;
	using u8 = oc::u8;

	using i64 = oc::i64;
	using i32 = oc::i32;
	using i16 = oc::i16;
	using i8 = oc::i8;

	using block  = oc::block;

	template<typename T>
	using span = oc::span<T>;
	template<typename T>
	using Matrix = oc::Matrix<T>;
	template<typename T>
	using MatrixView = oc::MatrixView<T>;

}



