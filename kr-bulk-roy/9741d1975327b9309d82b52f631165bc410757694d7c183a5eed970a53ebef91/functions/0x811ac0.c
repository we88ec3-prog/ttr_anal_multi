
void FUN_00811ac0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (in_EAX != param_1) {
    puVar3 = in_EAX + 10;
    do {
      puVar2 = (undefined4 *)*puVar3;
      if (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)puVar3[1];
        for (; puVar2 != puVar1; puVar2 = puVar2 + 7) {
          if (0xf < (uint)puVar2[5]) {
            FUN_0089120c(*puVar2);
          }
          puVar2[5] = 0xf;
          puVar2[4] = 0;
          *(undefined1 *)puVar2 = 0;
        }
        FUN_0089120c(*puVar3);
      }
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      if (0xf < (uint)puVar3[-5]) {
        FUN_0089120c(puVar3[-10]);
      }
      puVar3[-5] = 0xf;
      puVar3[-6] = 0;
      *(undefined1 *)(puVar3 + -10) = 0;
      puVar2 = puVar3 + 5;
      puVar3 = puVar3 + 0xf;
    } while (puVar2 != param_1);
  }
  return;
}

