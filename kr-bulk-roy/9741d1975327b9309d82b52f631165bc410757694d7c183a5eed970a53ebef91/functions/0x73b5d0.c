
undefined4 FUN_0073b5d0(void)

{
  uint in_EAX;
  char *in_ECX;
  
  if (in_EAX < 0x8876086b) {
    if (in_EAX == 0x8876086a) {
      _sprintf_s(in_ECX,0x400,
                 "D3DERR_NOTAVAILABLE - This device does not support the queried technique.");
      return 0;
    }
    if (in_EAX == 0) {
      return 0;
    }
    if (in_EAX == 0x8007000e) {
      _sprintf_s(in_ECX,0x400,
                 "E_OUTOFMEMORY - Direct3D could not allocate sufficient memory to complete the call."
                );
      return 1;
    }
    if (in_EAX == 0x8876017c) {
      _sprintf_s(in_ECX,0x400,
                 "D3DERR_OUTOFVIDEOMEMORY - Direct3D does not have enough display memory to perform the operation. The device is using more resources in a single scene than can fit simultaneously into video memory. Present, PresentEx, or CheckDeviceState  can return this error. Recovery is similar to D3DERR_DEVICEHUNG, though the application may want to reduce its per-frame memory usage as well to avoid having the error recur."
                );
      return 1;
    }
  }
  else {
    if (in_EAX == 0x8876086c) {
      _sprintf_s(in_ECX,0x400,
                 "D3DERR_INVALIDCALL - The method call is invalid. For example, a method\'s parameter may not be a valid pointer."
                );
      return 0;
    }
    if (in_EAX == 0x88760b59) {
      _sprintf_s(in_ECX,0x400,"D3DXERR_INVALIDDATA - The data is invalid.");
      return 0;
    }
  }
  _sprintf_s(in_ECX,0x400,"Code : %d, not defined error.");
  return 0;
}

