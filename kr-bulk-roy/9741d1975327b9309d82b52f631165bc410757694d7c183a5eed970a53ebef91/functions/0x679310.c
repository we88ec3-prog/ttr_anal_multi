
void FUN_00679310(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_EAX;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar3 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(in_EAX + 0x11c);
    uVar2 = *(undefined4 *)(in_EAX + 0x118);
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf4369;
    *puVar3 = FoxUI::FXUIEventI2::vftable;
    puVar3[5] = uVar2;
    puVar3[6] = uVar1;
  }
  FUN_004072a0();
  (**(code **)(**(int **)(in_EAX + 0xf8) + 0x19c))(0xffffffff,0xffffffff,0,0);
  (**(code **)(**(int **)(in_EAX + 0xf8) + 200))();
  FUN_00757710();
  (**(code **)(**(int **)(in_EAX + 0xfc) + 200))();
  *(undefined2 *)(in_EAX + 0x124) = 0;
  puVar3 = (undefined4 *)(in_EAX + 0x100);
  iVar4 = 5;
  do {
    (**(code **)(*(int *)*puVar3 + 0x1ac))(0xffffffff,0xffffffff,0,0,0);
    (**(code **)(*(int *)*puVar3 + 200))();
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  (**(code **)(**(int **)(in_EAX + 0x114) + 0x90))(0);
  FUN_00757710();
  (**(code **)(**(int **)(in_EAX + 0x120) + 0x94))(0);
  return;
}

