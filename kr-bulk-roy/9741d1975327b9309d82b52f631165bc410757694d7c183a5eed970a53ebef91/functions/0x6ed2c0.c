
wchar_t * FUN_006ed2c0(void)

{
  int in_EAX;
  wchar_t *pwVar1;
  int iVar2;
  wchar_t *_Str;
  
  if (in_EAX < 0x3154454e) {
    if (in_EAX == 0x3154454d) {
      _Str = L"D3DFMT_MULTI2_ARGB8";
      goto LAB_006ed530;
    }
    switch(in_EAX) {
    case 0:
      _Str = L"D3DFMT_UNKNOWN";
      break;
    default:
      goto switchD_006ed2e2_caseD_1;
    case 0x14:
      _Str = L"D3DFMT_R8G8B8";
      break;
    case 0x15:
      _Str = L"D3DFMT_A8R8G8B8";
      break;
    case 0x16:
      _Str = L"D3DFMT_X8R8G8B8";
      break;
    case 0x17:
      _Str = L"D3DFMT_R5G6B5";
      break;
    case 0x18:
      _Str = L"D3DFMT_X1R5G5B5";
      break;
    case 0x19:
      _Str = L"D3DFMT_A1R5G5B5";
      break;
    case 0x1a:
      _Str = L"D3DFMT_A4R4G4B4";
      break;
    case 0x1b:
      _Str = L"D3DFMT_R3G3B2";
      break;
    case 0x1c:
      _Str = L"D3DFMT_A8";
      break;
    case 0x1d:
      _Str = L"D3DFMT_A8R3G3B2";
      break;
    case 0x1e:
      _Str = L"D3DFMT_X4R4G4B4";
      break;
    case 0x1f:
      _Str = L"D3DFMT_A2B10G10R10";
      break;
    case 0x20:
      _Str = L"D3DFMT_A8B8G8R8";
      break;
    case 0x21:
      _Str = L"D3DFMT_X8B8G8R8";
      break;
    case 0x22:
      _Str = L"D3DFMT_G16R16";
      break;
    case 0x23:
      _Str = L"D3DFMT_A2R10G10B10";
      break;
    case 0x24:
      _Str = L"D3DFMT_A16B16G16R16";
      break;
    case 0x28:
      _Str = L"D3DFMT_A8P8";
      break;
    case 0x29:
      _Str = L"D3DFMT_P8";
      break;
    case 0x32:
      _Str = L"D3DFMT_L8";
      break;
    case 0x33:
      _Str = L"D3DFMT_A8L8";
      break;
    case 0x34:
      _Str = L"D3DFMT_A4L4";
      break;
    case 0x3c:
      _Str = L"D3DFMT_V8U8";
      break;
    case 0x3d:
      _Str = L"D3DFMT_L6V5U5";
      break;
    case 0x3e:
      _Str = L"D3DFMT_X8L8V8U8";
      break;
    case 0x3f:
      _Str = L"D3DFMT_Q8W8V8U8";
      break;
    case 0x40:
      _Str = L"D3DFMT_V16U16";
      break;
    case 0x43:
      _Str = L"D3DFMT_A2W10V10U10";
      break;
    case 0x46:
      _Str = L"D3DFMT_D16_LOCKABLE";
      break;
    case 0x47:
      _Str = L"D3DFMT_D32";
      break;
    case 0x49:
      _Str = L"D3DFMT_D15S1";
      break;
    case 0x4b:
      _Str = L"D3DFMT_D24S8";
      break;
    case 0x4d:
      _Str = L"D3DFMT_D24X8";
      break;
    case 0x4f:
      _Str = L"D3DFMT_D24X4S4";
      break;
    case 0x50:
      _Str = L"D3DFMT_D16";
      break;
    case 0x51:
      _Str = L"D3DFMT_L16";
      break;
    case 100:
      _Str = L"D3DFMT_VERTEXDATA";
      break;
    case 0x65:
      _Str = L"D3DFMT_INDEX16";
      break;
    case 0x66:
      _Str = L"D3DFMT_INDEX32";
      break;
    case 0x6e:
      _Str = L"D3DFMT_Q16W16V16U16";
      break;
    case 0x6f:
      _Str = L"D3DFMT_R16F";
      break;
    case 0x70:
      _Str = L"D3DFMT_G16R16F";
      break;
    case 0x71:
      _Str = L"D3DFMT_A16B16G16R16F";
      break;
    case 0x72:
      _Str = L"D3DFMT_R32F";
      break;
    case 0x73:
      _Str = L"D3DFMT_G32R32F";
      break;
    case 0x74:
      _Str = L"D3DFMT_A32B32G32R32F";
      break;
    case 0x75:
      _Str = L"D3DFMT_CxV8U8";
    }
  }
  else {
    if (in_EAX < 0x33545845) {
      if (in_EAX == 0x33545844) {
        _Str = L"D3DFMT_DXT3";
        goto LAB_006ed530;
      }
      if (in_EAX == 0x31545844) {
        _Str = L"D3DFMT_DXT1";
        goto LAB_006ed530;
      }
      if (in_EAX == 0x32545844) {
        _Str = L"D3DFMT_DXT2";
        goto LAB_006ed530;
      }
      if (in_EAX == 0x32595559) {
        _Str = L"D3DFMT_YUY2";
        goto LAB_006ed530;
      }
    }
    else {
      if (in_EAX == 0x34545844) {
        _Str = L"D3DFMT_DXT4";
        goto LAB_006ed530;
      }
      if (in_EAX == 0x35545844) {
        _Str = L"D3DFMT_DXT5";
        goto LAB_006ed530;
      }
      if (in_EAX == 0x59565955) {
        _Str = L"D3DFMT_UYVY";
        goto LAB_006ed530;
      }
    }
switchD_006ed2e2_caseD_1:
    _Str = L"Unknown format";
  }
LAB_006ed530:
  pwVar1 = _wcsstr(_Str,L"D3DFMT_");
  if (pwVar1 != (wchar_t *)0x0) {
    iVar2 = lstrlenW(L"D3DFMT_");
    return _Str + iVar2;
  }
  return _Str;
}

