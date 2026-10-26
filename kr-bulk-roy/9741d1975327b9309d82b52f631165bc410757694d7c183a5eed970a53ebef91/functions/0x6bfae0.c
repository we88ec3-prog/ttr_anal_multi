
void FUN_006bfae0(void)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  int *in_EDX;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  iVar2 = *in_EDX;
  puVar3 = *(undefined8 **)(iVar2 + 8);
  *puVar3 = 0x3ff0000000000000;
  *(undefined4 *)(puVar3 + 1) = 3;
  piVar1 = (int *)(iVar2 + 8);
  *piVar1 = *piVar1 + 0x10;
  iVar2 = *in_EDX;
  local_18[0] = FUN_006fec70(iVar2,"g_TutoEmployCharQuery",0x15);
  local_10 = 4;
  FUN_006fb9a0(iVar2,iVar2 + 0x48,local_18,*(int *)(iVar2 + 8) + -0x10);
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -0x10;
  return;
}

