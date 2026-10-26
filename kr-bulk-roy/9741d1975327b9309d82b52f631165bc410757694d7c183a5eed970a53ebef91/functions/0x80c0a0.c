
void FUN_0080c0a0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int in_EAX;
  
  puVar1 = *(undefined4 **)(in_EAX + 0x5c);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar3 = puVar2[2];
    iVar4 = *(int *)(*(int *)(iVar3 + 4) + 8);
    if (((*(byte *)(iVar4 + 0x20) & 1) != 0) && (*(int *)(iVar3 + 8) != 0)) {
      (**(code **)(**(int **)(iVar3 + 8) + 0x1c))(*(undefined4 *)(iVar4 + 0x24));
    }
  }
  return;
}

