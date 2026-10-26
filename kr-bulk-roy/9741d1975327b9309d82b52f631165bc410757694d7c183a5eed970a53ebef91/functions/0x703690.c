
uint FUN_00703690(void)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  
  iVar1 = _tolower(unaff_EDI);
  switch(iVar1) {
  case 0x61:
    uVar2 = _isalpha(in_EAX);
    break;
  default:
    return (uint)(unaff_EDI == in_EAX);
  case 99:
    uVar2 = _iscntrl(in_EAX);
    break;
  case 100:
    uVar2 = _isdigit(in_EAX);
    break;
  case 0x6c:
    uVar2 = _islower(in_EAX);
    break;
  case 0x70:
    uVar2 = _ispunct(in_EAX);
    break;
  case 0x73:
    uVar2 = _isspace(in_EAX);
    break;
  case 0x75:
    uVar2 = _isupper(in_EAX);
    break;
  case 0x77:
    uVar2 = _isalnum(in_EAX);
    break;
  case 0x78:
    uVar2 = _isxdigit(in_EAX);
    break;
  case 0x7a:
    uVar2 = (uint)(in_EAX == 0);
  }
  iVar1 = _islower(unaff_EDI);
  if (iVar1 != 0) {
    return uVar2;
  }
  return (uint)(uVar2 == 0);
}

