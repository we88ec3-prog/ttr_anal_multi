
undefined4 FUN_00706020(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((*(undefined4 **)(param_1 + 8) <= puVar1) || (puVar1 == &DAT_00c0bfc8)) || (puVar1[2] == -1))
  {
    FUN_006f5da0(1);
  }
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((puVar1 < *(undefined4 **)(param_1 + 8)) && (puVar1 != &DAT_00c0bfc8)) && (puVar1[2] != -1))
  {
    FUN_006f5510((&PTR_DAT_00c0be1c)[puVar1[2]]);
    return 1;
  }
  FUN_006f5510("no value");
  return 1;
}

