
undefined4 FUN_00709ca0(int param_1)

{
  double *pdVar1;
  __time64_t _Time1;
  __time64_t _Time2;
  undefined4 *puVar2;
  double dVar3;
  
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((puVar2 < *(undefined4 **)(param_1 + 8)) && (puVar2 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x18))) {
    FUN_006f6290(param_1,2);
  }
  FUN_006f6290(param_1,1);
  _Time1 = FUN_008fed46();
  _Time2 = FUN_008fed46();
  dVar3 = __difftime64(_Time1,_Time2);
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = dVar3;
  *(undefined4 *)(pdVar1 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

