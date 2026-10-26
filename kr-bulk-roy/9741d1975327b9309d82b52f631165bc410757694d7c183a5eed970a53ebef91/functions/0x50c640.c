
void FUN_0050c640(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined2 local_c;
  undefined1 uStack_a;
  undefined1 uStack_9;
  
  puVar3 = (undefined4 *)(param_1 * 0x10 + in_ECX);
  if ((*(char *)(puVar3 + 3) != '\0') && (puVar3[1] != 0)) {
    param_1 = *puVar3;
    iVar1 = FUN_004034e0();
    FUN_008438c0(&param_1);
    iVar2 = CONCAT13(uStack_9,CONCAT12(uStack_a,local_c));
    if ((iVar2 != *(int *)(iVar1 + 4)) && (iVar2 = *(int *)(iVar2 + 0x10), iVar2 != 0)) {
      if (*(int *)(iVar2 + 8) == 0x1a) {
        FUN_0040f060();
        iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))();
        if (iVar2 != 0) {
          iVar2 = FUN_004c9530();
          if (iVar2 != 0) {
            FUN_0050cac0();
            return;
          }
        }
      }
      else {
        FUN_0050cac0();
      }
    }
  }
  return;
}

