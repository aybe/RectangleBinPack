#pragma once

using namespace System;

namespace RectangleBinPack
{
	public ref class Disposable abstract
	{
		bool _isDisposed;

	protected:

		explicit Disposable() : _isDisposed(false)
		{
		}

		virtual void DisposeManaged()
		{
		}

		virtual void DisposeNative()
		{
		}

		virtual void DisposeObject(const bool disposing)
		{
			if (_isDisposed)
			{
				return;
			}

			if (disposing)
			{
				DisposeManaged();
			}

			DisposeNative();

			_isDisposed = true;
		}

		void ThrowIfDisposed()
		{
			if (_isDisposed)
			{
				throw gcnew ObjectDisposedException(this->GetType()->Name);
			}
		}

	public:

		property bool IsDisposed
		{
			bool get()
			{
				return _isDisposed;
			}
		}

		~Disposable()
		{
			DisposeObject(true);
			GC::SuppressFinalize(this);
		}

		!Disposable()
		{
			DisposeObject(false);
		}
	};
}
