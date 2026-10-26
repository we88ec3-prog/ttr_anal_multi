
void FUN_006425a0(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  iVar3 = *(int *)(*(int *)(in_EAX + 0x130) + 0x24c);
  if (iVar3 != 0) {
    iVar3 = *(int *)(iVar3 + 0xcc);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xdc);
    }
    if (iVar3 != 0) {
      switch(*(undefined4 *)(iVar3 + 0x20)) {
      case 0:
      case 1:
      case 3:
      case 4:
        FUN_00642e60(0,0,1);
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
            if ((int)piVar4 - iVar1 >> 1 != 0) {
              if (7 < *(uint *)(iVar3 + 0xfc)) {
                piVar5 = (int *)*piVar5;
              }
              FUN_00642e60(1,piVar5,1);
              return;
            }
          }
        }
        FUN_00642e60(1,0,1);
        return;
      }
    }
  }
  return;
}

