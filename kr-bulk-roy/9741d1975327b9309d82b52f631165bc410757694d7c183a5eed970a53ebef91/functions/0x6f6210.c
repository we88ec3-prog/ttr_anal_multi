
int FUN_006f6210(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  
  iVar1 = FUN_006f53f0();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)FUN_006f50f0();
    if ((puVar2 == &DAT_00c0bfc8) || (puVar2[2] == -1)) {
      pcVar3 = "no value";
    }
    else {
      pcVar3 = (&PTR_DAT_00c0be1c)[puVar2[2]];
    }
    FUN_006f5580(param_1,"%s expected, got %s","string",pcVar3);
    FUN_006f5da0();
  }
  return iVar1;
}

