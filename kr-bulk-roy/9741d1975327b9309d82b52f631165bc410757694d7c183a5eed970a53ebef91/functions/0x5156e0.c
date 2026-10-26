
undefined4 FUN_005156e0(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar1 = param_1;
  iVar2 = in_ECX;
  switch(in_ECX) {
  case 1:
  case 2:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    break;
  default:
    return 0;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x20:
  case 0x24:
  case 0x25:
    iVar2 = 3;
  }
  param_1 = CONCAT13((char)iVar2,(undefined3)param_1);
  FUN_00515a30();
  if ((in_ECX != *(int *)(iVar1 + 0x50)) &&
     (FUN_0062db10(&stack0x00000008), param_1 != *(int *)(in_ECX + 0x14))) {
    return *(undefined4 *)(param_1 + 0x14);
  }
  return 0;
}

