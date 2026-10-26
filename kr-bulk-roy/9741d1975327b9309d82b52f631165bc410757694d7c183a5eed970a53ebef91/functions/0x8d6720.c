
void FUN_008d6720(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = *param_1;
  FUN_008b8e60(param_1[0xb]);
  iVar2 = FUN_008b8a60(*(undefined4 *)(iVar1 + 500),param_2);
  if (iVar2 == 0) {
    piVar3 = (int *)(*(int *)(*(int *)(iVar1 + 500) + 0x58) + 0xc);
    piVar4 = param_1 + 3;
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    }
  }
  return;
}

