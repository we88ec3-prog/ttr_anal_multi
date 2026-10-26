
void FUN_00642470(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  
  iVar3 = *(int *)(*(int *)(in_EAX + 0x130) + 0x24c);
  if (iVar3 == 0) {
LAB_006424ab:
    iVar3 = -1;
  }
  else {
    iVar3 = *(int *)(iVar3 + 0xcc);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xdc);
    }
    if (iVar3 == 0) goto LAB_006424ab;
    iVar3 = *(int *)(iVar3 + 0x20);
  }
  switch((iVar3 + 1) % 5) {
  case 0:
  case 1:
  case 3:
  case 4:
    uVar6 = 0;
    break;
  case 2:
    iVar3 = *(int *)(*(int *)(in_EAX + 0x134) + 0x24c);
    if (iVar3 != 0) {
      iVar3 = *(int *)(iVar3 + 0xcc);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0xdc);
      }
      if (iVar3 != 0) {
        piVar5 = (int *)(iVar3 + 0xe8);
        piVar4 = piVar5;
        if (7 < *(uint *)(iVar3 + 0xfc)) {
          piVar4 = (int *)*piVar5;
        }
        iVar1 = (int)piVar4 + 2;
        do {
          iVar2 = *piVar4;
          piVar4 = (int *)((int)piVar4 + 2);
        } while ((short)iVar2 != 0);
        if ((int)piVar4 - iVar1 >> 1 == 0) {
          FUN_00642e60(1,0,1);
        }
        else {
          if (7 < *(uint *)(iVar3 + 0xfc)) {
            piVar5 = (int *)*piVar5;
          }
          FUN_00642e60(1,piVar5,1);
        }
        goto switchD_006424c6_default;
      }
    }
    uVar6 = 1;
    break;
  default:
    goto switchD_006424c6_default;
  }
  FUN_00642e60(uVar6,0,1);
switchD_006424c6_default:
  FUN_0075cd30(*(undefined4 *)(in_EAX + 0x130));
  (**(code **)(**(int **)(in_EAX + 0x130) + 200))();
  return;
}

