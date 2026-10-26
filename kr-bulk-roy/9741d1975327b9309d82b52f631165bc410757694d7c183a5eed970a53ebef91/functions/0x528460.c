
void FUN_00528460(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  
  if (in_EAX != param_1) {
    puVar2 = in_EAX + 7;
    do {
      if (puVar2[-2] != 0) {
        FUN_0089120c(puVar2[-2]);
      }
      puVar2[-2] = 0;
      puVar2[-1] = 0;
      *puVar2 = 0;
      if (puVar2[-6] != 0) {
        FUN_0089120c(puVar2[-6]);
      }
      puVar2[-6] = 0;
      puVar2[-5] = 0;
      puVar2[-4] = 0;
      puVar1 = puVar2 + 2;
      puVar2 = puVar2 + 9;
    } while (puVar1 != param_1);
  }
  return;
}

