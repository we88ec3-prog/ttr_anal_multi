
void FUN_0074fb50(void)

{
  int *piVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int in_ECX;
  char *pcVar8;
  int iStack_14;
  undefined1 auStack_10 [12];
  
  piVar1 = *(int **)(in_ECX + 0x13e0);
  if (piVar1 != *(int **)(in_ECX + 0x13cc)) {
    if ((piVar1 != (int *)0x0) && (iVar4 = (**(code **)(*piVar1 + 4))(), iVar4 != 53000)) {
      (**(code **)(**(int **)(in_ECX + 0x13e0) + 0xcc))();
    }
    if ((*(int **)(in_ECX + 0x13cc) != (int *)0x0) &&
       (iVar4 = (**(code **)(**(int **)(in_ECX + 0x13cc) + 4))(), iVar4 != 53000)) {
      (**(code **)(**(int **)(in_ECX + 0x13cc) + 0xcc))();
    }
  }
  if ((((*(int *)(in_ECX + 0xfc) == 1) || (*(int *)(in_ECX + 0xfc) == 6)) &&
      (*(int **)(in_ECX + 0x13d0) != (int *)0x0)) &&
     (iVar4 = (**(code **)(**(int **)(in_ECX + 0x13d0) + 4))(), iVar4 != 53000)) {
    (**(code **)(**(int **)(in_ECX + 0x13d0) + 0xcc))();
  }
  piVar1 = *(int **)(in_ECX + 0x13d0);
  if ((piVar1 != (int *)0x0) && (((uint)piVar1[10] >> 7 & 1) != 0)) {
    (**(code **)(*piVar1 + 0xb0))();
  }
  if (((*(int *)(in_ECX + 0xfc) == 6) && (piVar1 = *(int **)(in_ECX + 0x13c8), piVar1 != (int *)0x0)
      ) && (piVar6 = *(int **)(in_ECX + 0x13cc), piVar1 != piVar6)) {
    uVar2 = 0;
    if (((piVar6 != (int *)0x0) && (((uint)piVar6[10] >> 7 & 1) != 0)) &&
       ((*(byte *)(piVar1 + 10) & 8) != 0)) {
      iVar4 = *piVar6;
      uVar5 = (**(code **)(*piVar1 + 0xdc))(auStack_10);
      uVar2 = (**(code **)(iVar4 + 0x150))(uVar5);
    }
    (**(code **)(**(int **)(in_ECX + 0x13c8) + 0x154))(uVar2);
  }
  if (*(int *)(in_ECX + 0x13c8) == 0) {
    if ((*(int **)(in_ECX + 0x13cc) == (int *)0x0) ||
       (iVar4 = (**(code **)(**(int **)(in_ECX + 0x13cc) + 0x58))(), iVar4 == 0)) {
      *(undefined4 *)(in_ECX + 0x13ec) = 0;
    }
    else {
      if ((*(int *)(in_ECX + 0x13ec) != 0) &&
         (*(int **)(in_ECX + 0x13cc) == *(int **)(in_ECX + 0x13e0))) {
        piVar1 = *(int **)(in_ECX + 0x13ec);
        piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 0x13cc) + 0x58))();
        if (piVar6 == piVar1) {
          (**(code **)(*piVar1 + 0xb0))();
          goto LAB_0074fd4d;
        }
      }
      (**(code **)(**(int **)(in_ECX + 0x13cc) + 0x5c))();
      if (((uint)(*(int **)(in_ECX + 0x13cc))[10] >> 7 & 1) == 0) {
        *(undefined4 *)(in_ECX + 0x13ec) = 0;
      }
      else {
        (**(code **)(**(int **)(in_ECX + 0x13cc) + 0x58))();
        FUN_0074f980(in_ECX);
      }
    }
LAB_0074fd4d:
    if ((((*(int **)(in_ECX + 0x13f0) == (int *)0x0) ||
         (cVar3 = (**(code **)(**(int **)(in_ECX + 0x13f0) + 0x4c))(), cVar3 == '\0')) ||
        (*(int *)(*(int *)(in_ECX + 0x13f0) + 0x60) == 0)) ||
       (cVar3 = FUN_00746420(), cVar3 != '\0')) {
      if (*(char *)(in_ECX + 0x13f4) == '\0') {
        if ((*(int **)(in_ECX + 0x13cc) != (int *)0x0) && (*(int *)(in_ECX + 0x100) == 6)) {
          uVar5 = 1;
          (**(code **)(**(int **)(in_ECX + 0x13cc) + 0x44))(1);
          FUN_0074f840(in_ECX,uVar5);
          goto LAB_0074fdd4;
        }
        if (*(int **)(in_ECX + 0x13f0) == (int *)0x0) goto LAB_0074fdd4;
        if (*(int *)(in_ECX + 0xfc) == 6) {
          cVar3 = (**(code **)(**(int **)(in_ECX + 0x13f0) + 0x48))();
          if (cVar3 != '\0') {
            FUN_0074f940();
          }
          goto LAB_0074fdd4;
        }
      }
      else {
LAB_0074fdd4:
        if (*(int *)(in_ECX + 0xfc) == 6) goto LAB_0074fde4;
      }
      if (*(int *)(in_ECX + 0x100) != 6) goto LAB_0074fdeb;
    }
    else {
      FUN_0074f940();
    }
LAB_0074fde4:
    *(undefined1 *)(in_ECX + 0x13f4) = 0;
  }
  else {
    *(undefined4 *)(in_ECX + 0x13ec) = 0;
    if (*(int **)(in_ECX + 0x13f0) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0x13f0) + 0xd4))();
    }
    if (*(int **)(in_ECX + 0x13f0) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0x13f0) + 0x130))();
    }
    *(undefined4 *)(in_ECX + 0x13f0) = 0;
  }
LAB_0074fdeb:
  if (((0 < *(int *)(in_ECX + 0xb0)) &&
      ((float)*(int *)(in_ECX + 0xb0) < (float)*(int *)(in_ECX + 0xa0) * *(float *)(in_ECX + 0x13ac)
      )) && ((0 < *(int *)(in_ECX + 0xb4) &&
             ((float)*(int *)(in_ECX + 0xb4) <
              (float)*(int *)(in_ECX + 0xa4) * *(float *)(in_ECX + 0x13b0))))) {
    piVar1 = *(int **)(in_ECX + 0x13c8);
    if ((piVar1 != (int *)0x0) && ((*(byte *)(piVar1 + 10) & 8) != 0)) {
      piVar6 = *(int **)(in_ECX + 0x13cc);
      if (piVar6 == piVar1) {
        *(undefined4 *)(in_ECX + 0x14c0) = 0xd;
      }
      else if (piVar6 == (int *)0x0) {
        *(undefined4 *)(in_ECX + 0x14c0) = 0xd;
        (**(code **)(*piVar1 + 0x158))(1);
      }
      else {
        if (((uint)piVar6[10] >> 7 & 1) != 0) {
          iVar4 = *piVar6;
          uVar5 = (**(code **)(*piVar1 + 0xdc))(auStack_10);
          cVar3 = (**(code **)(iVar4 + 0x14c))(uVar5);
          if (cVar3 != '\0') {
            (**(code **)(**(int **)(in_ECX + 0x13cc) + 0xf4))();
            (**(code **)(**(int **)(in_ECX + 0x13c8) + 0x158))(1);
            goto LAB_0074ff4e;
          }
        }
        (**(code **)(**(int **)(in_ECX + 0x13cc) + 0xf8))();
        (**(code **)(**(int **)(in_ECX + 0x13c8) + 0x158))(0);
      }
      goto LAB_0074ff4e;
    }
    if ((*(int **)(in_ECX + 0x13d0) != (int *)0x0) && (*(int *)(in_ECX + 0xfc) == 3)) {
      (**(code **)(**(int **)(in_ECX + 0x13d0) + 0x100))();
      goto LAB_0074ff4e;
    }
    if (*(int **)(in_ECX + 0x13cc) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0x13cc) + 0xfc))();
      goto LAB_0074ff4e;
    }
  }
  *(undefined4 *)(in_ECX + 0x14c0) = 0;
LAB_0074ff4e:
  *(undefined4 *)(in_ECX + 0x13e0) = *(undefined4 *)(in_ECX + 0x13cc);
  *(undefined4 *)(in_ECX + 0x13e4) = *(undefined4 *)(in_ECX + 0x13d0);
  pcVar8 = (char *)(in_ECX + 0x1334);
  iVar4 = 0x54;
  iStack_14 = 3;
  do {
    if (*(int *)(iVar4 + 0xa8 + in_ECX) == 1) {
      if ((*(int **)(in_ECX + 0x13cc) == (int *)0x0) ||
         (iVar7 = (**(code **)(**(int **)(in_ECX + 0x13cc) + 4))(), iVar7 == 53000)) {
        cVar3 = '\0';
      }
      else {
        cVar3 = '\x01';
      }
      *pcVar8 = cVar3;
    }
    if (*pcVar8 != '\0') {
      *(undefined4 *)(iVar4 + 0xa8 + in_ECX) = 0;
      *(undefined4 *)(iVar4 + 0xb4 + in_ECX) = 0;
    }
    iVar4 = iVar4 + 4;
    pcVar8 = pcVar8 + 1;
    iStack_14 = iStack_14 + -1;
  } while (iStack_14 != 0);
  if ((*(int *)(in_ECX + 0x13d4) != 0) && (*(int *)(in_ECX + 0xc4) != 0)) {
    *(undefined4 *)(in_ECX + 0xc4) = 0;
  }
  return;
}

