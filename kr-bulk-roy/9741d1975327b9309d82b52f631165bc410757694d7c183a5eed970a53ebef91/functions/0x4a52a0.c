
void FUN_004a52a0(int *param_1)

{
  uint uVar1;
  undefined2 *puVar2;
  ushort *puVar3;
  char cVar4;
  int iVar5;
  int *in_ECX;
  int *piVar6;
  
  piVar6 = param_1;
  uVar1 = param_1[4];
  if (uVar1 < 0x70c) {
    if (uVar1 == 0x70b) {
      if (*(int *)(in_ECX[0x3f] + 0xcc) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(*(int *)(in_ECX[0x3f] + 0xcc) + 0xdc);
      }
      if ((iVar5 != 0) && (puVar3 = *(ushort **)(iVar5 + 0x254), puVar3 != (ushort *)0x0)) {
        iVar5 = in_ECX[0x42];
        in_ECX[0x43] = (int)puVar3;
        param_1 = (int *)(uint)*puVar3;
        FUN_004a4cc0(&param_1);
        param_1 = (int *)CONCAT31(param_1._1_3_,in_ECX != *(int **)(iVar5 + 4));
        FUN_004a5970(puVar3,param_1);
        return;
      }
    }
    else if (uVar1 == 0x578) {
      if (param_1[2] == *(int *)(in_ECX[0x41] + 0x20)) {
        (**(code **)(*in_ECX + 0xd4))();
        return;
      }
      if (param_1[2] == *(int *)(in_ECX[0x40] + 0x20)) {
        *(byte *)(in_ECX + 0x44) = (byte)(*(uint *)(in_ECX[0x40] + 0x28) >> 9) & 1;
        in_ECX[0x43] = 0;
        FUN_004a5520(in_ECX);
        return;
      }
    }
    else if (uVar1 == 0x70a) {
      if (*(int *)(in_ECX[0x3f] + 0xcc) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(*(int *)(in_ECX[0x3f] + 0xcc) + 0xdc);
      }
      if ((iVar5 != 0) && (puVar2 = *(undefined2 **)(iVar5 + 0x254), puVar2 != (undefined2 *)0x0)) {
        cVar4 = FUN_004a4b80(*puVar2);
        if (cVar4 != '\0') {
          param_1 = (int *)CONCAT22(*puVar2,0xf0);
          if (DAT_00fba798 == 0) {
            (**(code **)(*DAT_00fba854 + 0x10))(0,&param_1,4);
          }
          FUN_004a5970(puVar2,1);
          return;
        }
      }
    }
  }
  else if (uVar1 == 0x70c) {
    iVar5 = (**(code **)(*param_1 + 4))();
    if (iVar5 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      piVar6 = (int *)0x0;
    }
    piVar6 = (int *)piVar6[6];
    if (piVar6 != (int *)0x0) {
      iVar5 = (**(code **)(*piVar6 + 4))();
      if (iVar5 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        return;
      }
      if (((piVar6[0x95] != 0) && (piVar6[0x95] == *(int *)(in_ECX[0x42] + 0x10))) &&
         (param_1 = (int *)CONCAT22(param_1._2_2_,0xf1), DAT_00fba798 == 0)) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&param_1,2);
      }
    }
  }
  return;
}

