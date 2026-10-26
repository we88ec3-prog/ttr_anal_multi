
void FUN_00774720(int *param_1)

{
  int *piVar1;
  int in_EAX;
  uint uVar2;
  
  FUN_0077e060(in_EAX + 4,param_1,*(undefined4 *)(in_EAX + 0x278));
  uVar2 = 0;
  if (*(int *)(in_EAX + 0x26c) - *(int *)(in_EAX + 0x268) >> 2 != 0) {
    do {
      FUN_0077e060(*(undefined4 *)(*(int *)(in_EAX + 0x268) + uVar2 * 4),param_1,
                   *(undefined4 *)(in_EAX + 0x278));
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(in_EAX + 0x26c) - *(int *)(in_EAX + 0x268) >> 2));
  }
  FUN_00774490();
  (**(code **)(*param_1 + 0xec))(param_1,1,(undefined4 *)(in_EAX + 0x220));
  piVar1 = *(int **)(in_EAX + 0x220);
  (**(code **)(*piVar1 + 0x10))(piVar1);
  return;
}

