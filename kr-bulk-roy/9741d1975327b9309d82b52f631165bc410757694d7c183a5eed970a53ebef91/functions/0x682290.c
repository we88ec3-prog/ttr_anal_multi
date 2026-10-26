
void FUN_00682290(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_EAX;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  int local_14;
  
  iVar1 = *(int *)(in_EAX + 0x120);
  iVar2 = *(int *)(in_EAX + 0x104);
  iVar3 = *(int *)(in_EAX + 0x100);
  local_14 = 0;
  iVar5 = iVar1 * 0x50;
  puVar6 = (undefined4 *)(in_EAX + 0xd8);
  do {
    if (local_14 + iVar1 * 10 < iVar2 - iVar3 >> 3) {
      iVar4 = *(int *)(in_EAX + 0x100);
      if (*(int *)(in_EAX + 0xd0) != 3) {
        uVar9 = *(undefined1 *)(iVar4 + 4 + iVar5);
        uVar8 = *(undefined1 *)(iVar4 + 6 + iVar5);
        uVar7 = *(undefined4 *)(iVar4 + iVar5);
        goto LAB_00682348;
      }
      FUN_005d7f50(*(undefined4 *)(iVar4 + iVar5),*(undefined1 *)(iVar4 + iVar5 + 5),
                   *(undefined1 *)(iVar4 + 6 + iVar5),*(undefined1 *)(iVar4 + 4 + iVar5));
      (**(code **)(*(int *)*puVar6 + 200))();
    }
    else {
      uVar9 = 0;
      uVar8 = 0;
      uVar7 = 0xffffffff;
LAB_00682348:
      FUN_005d7f50(uVar7,0xffffffff,uVar8,uVar9);
      (**(code **)(*(int *)*puVar6 + 200))();
    }
    local_14 = local_14 + 1;
    puVar6 = puVar6 + 1;
    iVar5 = iVar5 + 8;
    if (9 < local_14) {
      FUN_007597b0(0);
      FUN_007597b0(1);
      (**(code **)(**(int **)(in_EAX + 0x114) + 200))();
      return;
    }
  } while( true );
}

