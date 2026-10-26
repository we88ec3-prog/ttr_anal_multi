
void FUN_005800f0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (in_EAX != param_1) {
    puVar3 = in_EAX + 9;
    do {
      puVar2 = (undefined4 *)*puVar3;
      if (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)puVar3[1];
        for (; puVar2 != puVar1; puVar2 = puVar2 + 7) {
          if (7 < (uint)puVar2[5]) {
            FUN_0089120c(*puVar2);
          }
          puVar2[5] = 7;
          puVar2[4] = 0;
          *(undefined2 *)puVar2 = 0;
        }
        FUN_0089120c(*puVar3);
      }
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      if (0xf < (uint)puVar3[-2]) {
        FUN_0089120c(puVar3[-7]);
      }
      puVar3[-2] = 0xf;
      puVar3[-3] = 0;
      *(undefined1 *)(puVar3 + -7) = 0;
      puVar2 = puVar3 + 4;
      puVar3 = puVar3 + 0xd;
    } while (puVar2 != param_1);
  }
  return;
}

