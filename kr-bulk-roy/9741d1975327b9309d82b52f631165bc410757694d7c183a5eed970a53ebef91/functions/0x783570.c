
int FUN_00783570(char *param_1,size_t param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(FILE **)(in_ECX + 0x54) != (FILE *)0x0) {
    if ((param_1 == (char *)0x0) && (param_2 == 0 && param_3 == 0)) {
      iVar2 = 4;
    }
    else {
      iVar2 = 0;
    }
    iVar2 = _setvbuf(*(FILE **)(in_ECX + 0x54),param_1,iVar2,param_2);
    if (iVar2 == 0) {
      iVar2 = *(int *)(in_ECX + 0x54);
      *(undefined1 *)(in_ECX + 0x49) = 0;
      *(undefined1 *)(in_ECX + 0x50) = 1;
      FUN_00730d00();
      if (iVar2 != 0) {
        *(int *)(in_ECX + 0x10) = iVar2 + 8;
        *(int *)(in_ECX + 0x14) = iVar2 + 8;
        *(int *)(in_ECX + 0x20) = iVar2;
        *(int *)(in_ECX + 0x24) = iVar2;
        *(int *)(in_ECX + 0x30) = iVar2 + 4;
        *(int *)(in_ECX + 0x34) = iVar2 + 4;
      }
      uVar1 = DAT_00fe31e4;
      *(int *)(in_ECX + 0x54) = iVar2;
      *(undefined4 *)(in_ECX + 0x4c) = uVar1;
      *(undefined4 *)(in_ECX + 0x44) = 0;
      return in_ECX;
    }
  }
  return 0;
}

