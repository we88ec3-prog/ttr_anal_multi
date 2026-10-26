
void FUN_00514f50(void)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_10;
  uint local_c;
  undefined2 local_6;
  
  if (in_EAX != 0) {
    iVar2 = FUN_0072e360();
    while (iVar2 != 0) {
      iVar2 = FUN_007300a0(&DAT_00c0e1d8);
      if (iVar2 == 0) {
LAB_00514fa4:
        local_c = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_00514fa4;
        local_c = FUN_008917b4(puVar3);
      }
      local_c = local_c & 0xff;
      iVar2 = FUN_007300a0("CLASS");
      if (iVar2 == 0) {
LAB_00514fd3:
        local_10 = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_00514fd3;
        local_10 = FUN_008917b4(puVar3);
      }
      iVar2 = FUN_007300a0("CHARGE");
      if (iVar2 != 0) {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 != (undefined4 *)0x0) {
          FUN_008917b4(puVar3);
        }
      }
      iVar2 = FUN_007300a0("LEVEL");
      if (iVar2 == 0) {
LAB_0051502b:
        cVar1 = '\0';
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_0051502b;
        cVar1 = FUN_008917b4(puVar3);
      }
      if (cVar1 != '\0') {
        cVar1 = cVar1 + -1;
      }
      local_6 = CONCAT11(cVar1,(undefined1)local_c);
      uVar4 = FUN_00829960(&DAT_00fe3030,&local_10);
      uVar5 = FUN_004ca670();
      FUN_008262f0(uVar4,uVar5);
      iVar2 = FUN_0072e3c0();
    }
  }
  return;
}

