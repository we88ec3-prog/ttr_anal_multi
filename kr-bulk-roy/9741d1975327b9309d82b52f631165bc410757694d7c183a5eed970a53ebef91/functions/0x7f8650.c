
void FUN_007f8650(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  uint uVar1;
  uint uVar2;
  
  uVar1 = (*(int *)(in_EAX + 0x88) - *(int *)(in_EAX + 0x84)) / 0x48;
  uVar2 = uVar1 >> 2;
  if ((uVar1 & 3) != 0) {
    uVar2 = uVar2 + 1;
  }
  (**(code **)(**(int **)(in_EAX + 4) + 0xe8))(*(int **)(in_EAX + 4),*(undefined4 *)(in_EAX + 8));
  (**(code **)(**(int **)(in_EAX + 4) + 0xfc))(*(int **)(in_EAX + 4),0,0);
  (**(code **)(**(int **)(in_EAX + 4) + 0x78))
            (*(int **)(in_EAX + 4),*(undefined4 *)(in_EAX + 0x10),*(undefined4 *)(in_EAX + 0x5c));
  uVar1 = 0;
  if (uVar2 != 0) {
    do {
      FUN_007f84e0(param_1,param_2,param_3);
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar2);
  }
  (**(code **)(**(int **)(in_EAX + 4) + 0x10c))(*(int **)(in_EAX + 4));
  return;
}

