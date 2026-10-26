
/* WARNING: Removing unreachable block (ram,0x007eb188) */

void FUN_007eb0e0(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int *_Str1;
  int iVar3;
  char *_Str1_00;
  int iVar4;
  int *in_ECX;
  undefined1 *puVar5;
  uint local_4c;
  uint local_38;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009388b0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX != (int *)0x0) {
    (**(code **)(*in_ECX + 0x14))(uVar1);
    piVar2 = (int *)FUN_0072e2e0("Cache");
    while (piVar2 != (int *)0x0) {
      FUN_00402a70(&DAT_00c0d66c,4);
      local_8 = 0;
      puVar5 = &DAT_00bf2375;
      (**(code **)(*piVar2 + 0x14))(&DAT_00bf2375);
      FUN_0072ecf0(puVar5);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_007e2bb0();
      for (piVar2 = (int *)piVar2[0x10]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0x10]) {
        _Str1 = piVar2 + 8;
        if (0xf < (uint)piVar2[0xd]) {
          _Str1 = (int *)*_Str1;
        }
        iVar3 = __stricmp((char *)_Str1,"Cache");
        if (iVar3 == 0) goto LAB_007eb1ea;
      }
      piVar2 = (int *)0x0;
LAB_007eb1ea:
      local_8 = 0xffffffff;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
      local_38 = 0xf;
      local_4c = local_4c & 0xffffff00;
    }
    iVar3 = FUN_0072e2e0("Instance");
joined_r0x007eb22b:
    if (iVar3 != 0) {
      FUN_007eb290(param_1);
      for (iVar3 = *(int *)(iVar3 + 0x40); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x40)) {
        _Str1_00 = (char *)(iVar3 + 0x20);
        if (0xf < *(uint *)(iVar3 + 0x34)) {
          _Str1_00 = *(char **)_Str1_00;
        }
        iVar4 = __stricmp(_Str1_00,"Instance");
        if (iVar4 == 0) goto joined_r0x007eb22b;
      }
      iVar3 = 0;
      goto joined_r0x007eb22b;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

