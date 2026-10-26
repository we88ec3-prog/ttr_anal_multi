
void FUN_0068fed0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  
  uVar3 = *(uint *)(param_1 + 0x10);
  if (uVar3 < 0x70b) {
    if (uVar3 == 0x70a) {
LAB_00690301:
      FUN_0068f6a0(in_ECX);
      return;
    }
    if (uVar3 == 0x578) {
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)) {
        FUN_0068fdc0(in_ECX);
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) goto LAB_00690301;
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0x114) + 0x20)) {
        FUN_0068fc10();
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0x118) + 0x20)) {
        FUN_0068fb40();
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0x11c) + 0x20)) {
        FUN_0068fcd0(in_ECX);
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 300) + 0x20)) {
        if (0 < *(int *)(in_ECX + 0x200)) {
          FUN_006904b0(*(int *)(in_ECX + 0x200) + -1);
          return;
        }
      }
      else if (iVar2 == *(int *)(*(int *)(in_ECX + 0x130) + 0x20)) {
        iVar2 = *(int *)(in_ECX + 0x200) + 1;
        if (iVar2 < *(int *)(in_ECX + 0x204)) {
          FUN_006904b0(iVar2);
          return;
        }
      }
      else {
        if (iVar2 == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
          FUN_006904b0(0);
          return;
        }
        if (iVar2 == *(int *)(*(int *)(in_ECX + 0x10c) + 0x20)) {
          FUN_0068f900();
          return;
        }
        if (iVar2 == *(int *)(*(int *)(in_ECX + 0x110) + 0x20)) {
          FUN_0068f9c0(in_ECX);
          return;
        }
        if (iVar2 == *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
          FUN_0041a4d0();
          FUN_0053bc60(*(undefined1 *)(in_ECX + 0x208),*(undefined1 *)(in_ECX + 0x20c));
          return;
        }
        if (iVar2 == *(int *)(*(int *)(in_ECX + 0x120) + 0x20)) {
          FUN_00690f10(*(char *)(in_ECX + 0x5a0) == '\0');
          *(bool *)(in_ECX + 0x5a0) = *(char *)(in_ECX + 0x5a0) == '\0';
          return;
        }
      }
    }
    else if (uVar3 == 0x641) {
      if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0x134) + 0x20)) {
        if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x138) + 0x20)) {
          iVar2 = FUN_0075cdb0();
          iVar2 = *(int *)(iVar2 + 0x24c);
          *(int *)(in_ECX + 0x20c) = iVar2;
          (**(code **)(**(int **)(in_ECX + 0x110) + 0x90))(iVar2 != 0);
          (**(code **)(**(int **)(in_ECX + 0x100) + 0x90))(*(int *)(in_ECX + 0x20c) != 0);
          iVar2 = FUN_0075cdd0();
          if (iVar2 == 2) {
            FUN_00419bc0();
            iVar2 = FUN_004a7ef0();
            if (iVar2 != 0) {
              FUN_00404ba0();
              iVar1 = **(int **)(in_ECX + 0x110);
              uVar3 = FUN_004a7810(iVar2);
              iVar4 = FUN_004d43d0();
              (**(code **)(iVar1 + 0x90))((int)(uVar3 & 0xff) < iVar4);
              FUN_00404ba0();
              iVar1 = **(int **)(in_ECX + 0x100);
              uVar3 = FUN_004a7810(iVar2);
              iVar2 = FUN_004d43d0();
              (**(code **)(iVar1 + 0x90))((int)(uVar3 & 0xff) < iVar2);
            }
          }
          iVar2 = FUN_0075cdd0();
          if (iVar2 == 3) {
            FUN_00446230();
            iVar2 = FUN_004a7ef0();
            if (iVar2 != 0) {
              FUN_00404ba0();
              iVar1 = **(int **)(in_ECX + 0x110);
              uVar3 = FUN_00445330(iVar2);
              iVar4 = FUN_004d43d0();
              (**(code **)(iVar1 + 0x90))((int)(uVar3 & 0xff) < iVar4);
              FUN_00404ba0();
              iVar1 = **(int **)(in_ECX + 0x100);
              uVar3 = FUN_00445330(iVar2);
              iVar2 = FUN_004d43d0();
              (**(code **)(iVar1 + 0x90))((int)(uVar3 & 0xff) < iVar2);
            }
          }
          FUN_00691780();
        }
        FUN_006904b0(0);
        return;
      }
      FUN_00690b30();
      iVar2 = FUN_0075cdb0();
      iVar2 = *(int *)(iVar2 + 0x248);
      *(int *)(in_ECX + 0x208) = iVar2;
      if ((*(uint *)(*(int *)(in_ECX + 0x138) + 0x28) >> 7 & 1) != 0) {
        FUN_0075cd30(*(int *)(in_ECX + 0x138));
        *(undefined4 *)(in_ECX + 0x20c) = 0;
        (**(code **)(**(int **)(in_ECX + 0x110) + 0x90))(0);
        (**(code **)(**(int **)(in_ECX + 0x100) + 0x90))(0);
        FUN_00691780();
        FUN_006904b0(0);
        return;
      }
      (**(code **)(**(int **)(in_ECX + 0x100) + 0x90))(iVar2 != 0);
      FUN_00691780();
      FUN_006904b0(0);
      return;
    }
  }
  else if (uVar3 == 0x70b) {
    (**(code **)(**(int **)(in_ECX + 0x104) + 0x90))(1);
    (**(code **)(**(int **)(in_ECX + 0x108) + 0x90))(1);
  }
  else if (uVar3 == 0xf439b) {
    FUN_00690360(in_ECX);
    return;
  }
  return;
}

