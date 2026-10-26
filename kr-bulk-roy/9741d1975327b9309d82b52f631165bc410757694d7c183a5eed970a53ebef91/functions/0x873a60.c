
undefined4 FUN_00873a60(int param_1)

{
  int in_ECX;
  int iVar1;
  uint uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  if (*(undefined4 **)(in_ECX + 0x30) != (undefined4 *)0x0) {
    uStack_34 = 1;
    uStack_38 = 0x873a84;
    (**(code **)**(undefined4 **)(in_ECX + 0x30))();
    *(undefined4 *)(in_ECX + 0x30) = 0;
  }
  if (*(undefined4 **)(in_ECX + 0x38) != (undefined4 *)0x0) {
    uStack_34 = 1;
    uStack_38 = 0x873aa0;
    (**(code **)**(undefined4 **)(in_ECX + 0x38))();
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  if (*(undefined4 **)(in_ECX + 0x34) != (undefined4 *)0x0) {
    uStack_34 = 1;
    uStack_38 = 0x873ab8;
    (**(code **)**(undefined4 **)(in_ECX + 0x34))();
    *(undefined4 *)(in_ECX + 0x34) = 0;
  }
  uStack_34 = 0x873ac9;
  FUN_00781ea0();
  uStack_40 = *(uint *)(param_1 + 0x84);
  uStack_34 = 0;
  uStack_38 = 4;
  uStack_3c = in_ECX + 0x2c;
  FUN_006ddcc0();
  iVar1 = *(int *)(param_1 + 0x84);
  FUN_006ddcc0(iVar1,in_ECX + 0x28,4,0);
  uStack_40 = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&uStack_40,4,0);
  uStack_3c = iVar1 >> 0x10 & 0xff;
  uStack_40 = iVar1 >> 8 & 0xff;
  FUN_00785120(param_1);
  FUN_007851e0(param_1);
  FUN_00785120(param_1);
  return 1;
}

