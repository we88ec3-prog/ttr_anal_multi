
void FUN_008df0c0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*param_1 + 0x290);
  puVar1 = (undefined4 *)param_1[10];
  if ((puVar1 != (undefined4 *)0x0) && (iVar2 = FUN_008df080(), iVar2 != 0)) {
    (**(code **)(iVar2 + 8))(*puVar1);
    for (iVar3 = *(int *)(iVar3 + 0x768); iVar3 != 0; iVar3 = iVar3 + -1) {
      (**(code **)(iVar2 + 8))(puVar1[iVar3]);
    }
  }
  return;
}

