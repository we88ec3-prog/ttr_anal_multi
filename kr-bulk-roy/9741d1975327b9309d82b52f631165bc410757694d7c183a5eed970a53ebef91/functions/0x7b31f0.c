
undefined4 FUN_007b31f0(int *param_1,char *param_2,undefined4 param_3)

{
  char *_Str1;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *_Str2;
  
  uVar3 = param_1[1] - *param_1 >> 2;
  uVar4 = 0;
  if (uVar3 != 0) {
    do {
      _Str2 = param_2;
      _Str1 = (char *)(**(code **)(**(int **)(*param_1 + uVar4 * 4) + 8))();
      iVar1 = __stricmp(_Str1,_Str2);
      if (iVar1 == 0) {
        uVar2 = (**(code **)(**(int **)(*param_1 + uVar4 * 4) + 0xc))(param_3);
        return uVar2;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  return 0;
}

