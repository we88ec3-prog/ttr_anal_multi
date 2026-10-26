
undefined4 FUN_00847cb0(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *_Dst;
  
  iVar3 = 0;
  if (*(int *)(param_1 + 0x78) == 0) {
    return 0;
  }
  iVar1 = FUN_00857520(0);
  if (iVar1 != 0) {
    iVar3 = *(int *)(iVar1 + 8);
  }
  iVar2 = FUN_00857520(3);
  if (iVar2 != 0) {
    FUN_00857520(6);
    FUN_00857520(7);
  }
  if ((*(int *)(param_1 + 0x8c) != 0) && (*(float *)(param_1 + 0x90) != 0.0)) {
    _Dst = (void *)0x0;
    FUN_00845670();
    if (iVar1 != 0) {
      _Dst = (void *)FUN_008456c0();
      _memset(_Dst,0,iVar3 * 0xc);
    }
    FUN_00845930(_Dst,**(undefined4 **)(param_1 + 0x94),**(undefined4 **)(param_1 + 0x98),iVar3,
                 *(undefined4 *)(param_1 + 0x90));
    *param_2 = _Dst;
    return 1;
  }
  *param_2 = **(undefined4 **)(param_1 + 0x94);
  return 1;
}

