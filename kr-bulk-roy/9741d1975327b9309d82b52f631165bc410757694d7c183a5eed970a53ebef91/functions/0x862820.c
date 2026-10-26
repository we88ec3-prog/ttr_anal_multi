
undefined4 FUN_00862820(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  uint *in_EAX;
  int in_ECX;
  int iVar4;
  int *piVar5;
  undefined4 local_18;
  undefined4 local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  if ((in_ECX != 0) && (*(int *)(in_ECX + 8) != 0)) {
    FUN_004e7330(10);
    piVar5 = *(int **)(in_ECX + 4);
    local_c = (int *)*piVar5;
    local_8 = 0;
    local_10 = piVar5;
    if (local_c != piVar5) {
      local_18 = 0;
      local_14 = 0;
      do {
        piVar3 = local_c;
        local_14 = CONCAT31(local_14._1_3_,(char)local_c[4]);
        puVar1 = (undefined4 *)in_EAX[1];
        local_18 = CONCAT22((undefined2)local_8,(undefined2)local_18);
        local_14 = CONCAT13((char)local_c[5],CONCAT12((char)local_c[3],(undefined2)local_14));
        if ((&local_18 < puVar1) && ((undefined4 *)*in_EAX <= &local_18)) {
          iVar4 = (int)&local_18 - (int)*in_EAX >> 3;
          if (puVar1 == (undefined4 *)in_EAX[2]) {
            FUN_007cddf0();
          }
          puVar1 = (undefined4 *)in_EAX[1];
          piVar5 = local_10;
          if (puVar1 != (undefined4 *)0x0) {
            uVar2 = *in_EAX;
            *puVar1 = *(undefined4 *)(uVar2 + iVar4 * 8);
            puVar1[1] = *(undefined4 *)(uVar2 + 4 + iVar4 * 8);
          }
        }
        else {
          if (puVar1 == (undefined4 *)in_EAX[2]) {
            FUN_007cddf0();
          }
          puVar1 = (undefined4 *)in_EAX[1];
          if (puVar1 != (undefined4 *)0x0) {
            *puVar1 = local_18;
            puVar1[1] = local_14;
          }
        }
        in_EAX[1] = in_EAX[1] + 8;
        switch(piVar3[4]) {
        case 0:
        case 4:
        case 5:
        case 6:
          iVar4 = 4;
          break;
        case 1:
        case 7:
          iVar4 = 8;
          break;
        case 2:
          iVar4 = 0xc;
          break;
        case 3:
          iVar4 = 0x10;
          break;
        default:
          iVar4 = 0;
        }
        local_8 = local_8 + iVar4;
        FUN_0085e240();
      } while (local_c != piVar5);
    }
    local_18 = 0xff;
    local_14 = 0x11;
    FUN_007d4560();
    return 1;
  }
  return 0;
}

