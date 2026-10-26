
void FUN_00510f60(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  
  if (in_EAX != param_1) {
    puVar2 = in_EAX + 10;
    do {
      if (puVar2[-1] != 0) {
        FUN_0049ad50(param_1);
        FUN_0089120c(puVar2[-1]);
      }
      puVar2[-1] = 0;
      *puVar2 = 0;
      puVar2[1] = 0;
      if (7 < (uint)puVar2[-3]) {
        FUN_0089120c(puVar2[-8]);
      }
      puVar2[-3] = 7;
      puVar2[-4] = 0;
      *(undefined2 *)(puVar2 + -8) = 0;
      puVar1 = puVar2 + 3;
      puVar2 = puVar2 + 0xd;
    } while (puVar1 != param_1);
  }
  return;
}

