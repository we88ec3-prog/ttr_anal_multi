
void FUN_0087c480(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  int *unaff_ESI;
  int *piVar1;
  undefined4 uStack_6c;
  int *piStack_68;
  int iStack_64;
  int *piStack_60;
  int *piStack_5c;
  undefined4 uStack_58;
  int *piStack_54;
  float fStack_44;
  int local_40;
  undefined4 local_3c;
  undefined1 auStack_38 [4];
  uint uStack_34;
  uint uStack_2c;
  int iStack_24;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&fStack_44;
  local_3c = param_3;
  if ((param_4 == 0) || (param_2 == (int *)0x0)) {
    __security_check_cookie(local_c ^ (uint)&fStack_44);
    return;
  }
  piVar1 = (int *)0x0;
  if (*(int *)(param_4 + 0xec) != 0) {
    piStack_54 = *(int **)(param_4 + 0xec);
    uStack_58 = 0x87c4cc;
    (**(code **)(*piStack_54 + 4))();
    piVar1 = *(int **)(param_4 + 0xec);
  }
  piStack_54 = &local_40;
  local_40 = 0;
  uStack_58 = 0;
  piStack_60 = (int *)0x87c4ec;
  piStack_5c = piVar1;
  (**(code **)(*piVar1 + 0x98))();
  if (unaff_ESI != (int *)0x0) {
    piStack_60 = (int *)auStack_38;
    piStack_68 = (int *)0x87c505;
    (**(code **)(*unaff_ESI + 0x30))();
    fStack_44 = (float)iStack_24;
    if (iStack_24 < 0) {
      fStack_44 = fStack_44 + 4.2949673e+09;
    }
    if (piStack_54 != (int *)0x0) {
      piStack_68 = piStack_54;
      uStack_6c = 0x87c541;
      (**(code **)(*piStack_54 + 8))();
      piStack_54 = (int *)0x0;
    }
    uStack_6c = 0x87c551;
    piStack_68 = piVar1;
    (**(code **)(*piVar1 + 8))();
    uStack_6c = 2;
    (**(code **)(*param_2 + 0x80))(param_2,piStack_54,&stack0xffffffb4);
    __security_check_cookie(uStack_34 ^ (uint)&uStack_6c);
    return;
  }
  iStack_64 = 0x87c587;
  piStack_60 = piVar1;
  (**(code **)(*piVar1 + 8))();
  iStack_64 = param_4;
  piStack_68 = (int *)0x87c591;
  piStack_68 = (int *)FUN_0083d790();
  iStack_64 = 2;
  (**(code **)(*param_2 + 0x80))(param_2);
  piStack_68 = (int *)0x87c5b7;
  __security_check_cookie(uStack_2c ^ (uint)&iStack_64);
  return;
}

