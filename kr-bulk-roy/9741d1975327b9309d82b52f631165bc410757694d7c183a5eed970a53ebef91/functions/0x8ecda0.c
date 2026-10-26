
void FUN_008ecda0(void)

{
  short sVar1;
  int in_EAX;
  int iVar2;
  
  sVar1 = *(short *)(in_EAX + 0x12a);
  if (sVar1 == 0x4000) {
    iVar2 = (int)*(short *)(in_EAX + 0x126);
  }
  else {
    if (*(short *)(in_EAX + 300) == 0x4000) {
      *(int *)(in_EAX + 0x234) = (int)*(short *)(in_EAX + 0x128);
      goto LAB_008ece01;
    }
    iVar2 = (int)*(short *)(in_EAX + 0x128) * (int)*(short *)(in_EAX + 300) +
            (int)*(short *)(in_EAX + 0x126) * (int)sVar1 >> 0xe;
  }
  *(int *)(in_EAX + 0x234) = iVar2;
LAB_008ece01:
  if (*(short *)(in_EAX + 0x126) == 0x4000) {
    *(code **)(in_EAX + 0x23c) = FUN_008ecd80;
  }
  else if (*(short *)(in_EAX + 0x128) == 0x4000) {
    *(code **)(in_EAX + 0x23c) = FUN_008ecd90;
  }
  else {
    *(code **)(in_EAX + 0x23c) = FUN_008ecd20;
  }
  if (*(short *)(in_EAX + 0x122) == 0x4000) {
    *(code **)(in_EAX + 0x240) = FUN_008ecd80;
  }
  else if (*(short *)(in_EAX + 0x124) == 0x4000) {
    *(code **)(in_EAX + 0x240) = FUN_008ecd90;
  }
  else {
    *(code **)(in_EAX + 0x240) = FUN_008ecd50;
  }
  iVar2 = *(int *)(in_EAX + 0x234);
  *(code **)(in_EAX + 0x248) = FUN_008ec6f0;
  *(code **)(in_EAX + 0x24c) = FUN_008ec780;
  if (iVar2 == 0x4000) {
    if (sVar1 == 0x4000) {
      *(code **)(in_EAX + 0x248) = FUN_008ec7f0;
      *(code **)(in_EAX + 0x24c) = FUN_008ec850;
    }
    else if (*(short *)(in_EAX + 300) == 0x4000) {
      *(code **)(in_EAX + 0x248) = FUN_008ec820;
      *(code **)(in_EAX + 0x24c) = FUN_008ec870;
    }
  }
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  *(undefined4 *)(in_EAX + 0x100) = 0;
  if (iVar2 < 0x400) {
    *(undefined4 *)(in_EAX + 0x234) = 0x4000;
  }
  return;
}

