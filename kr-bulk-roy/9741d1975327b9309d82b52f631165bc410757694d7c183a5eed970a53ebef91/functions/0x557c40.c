
void FUN_00557c40(undefined4 *param_1)

{
  uint *in_EAX;
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  bool bVar3;
  undefined4 local_c;
  undefined4 *local_8;
  
  local_8 = *(undefined4 **)(in_ECX + 4);
  bVar3 = true;
  local_c = CONCAT31(local_c._1_3_,1);
  if (*(char *)((int)local_8[1] + 0x15) == '\0') {
    puVar1 = (undefined4 *)local_8[1];
    do {
      local_8 = puVar1;
      bVar3 = *in_EAX < (uint)local_8[3];
      local_c = CONCAT31(local_c._1_3_,bVar3);
      if (bVar3) {
        puVar1 = (undefined4 *)*local_8;
      }
      else {
        puVar1 = (undefined4 *)local_8[2];
      }
    } while (*(char *)((int)puVar1 + 0x15) == '\0');
  }
  if (bVar3) {
    if (local_8 == (undefined4 *)**(int **)(in_ECX + 4)) {
      uVar2 = FUN_0057ef20();
      FUN_0044bd00(&local_c,1,uVar2);
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = local_c;
      return;
    }
    FUN_0053f8a0();
  }
  if ((uint)local_8[3] < *in_EAX) {
    uVar2 = FUN_0057ef20();
    FUN_0044bd00(&local_c,local_c,uVar2);
    *param_1 = local_c;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = local_8;
  return;
}

