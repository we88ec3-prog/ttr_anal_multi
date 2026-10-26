
int * FUN_005ad9f0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *in_EAX;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  piVar3 = (int *)(**(code **)(*(int *)in_EAX[0x90] + 0x28))();
  piVar1 = (int *)in_EAX[0x93];
  piVar7 = (int *)*piVar1;
  if ((param_1 != (int *)0x0) && (iVar4 = (**(code **)(*param_1 + 4))(), iVar4 != 0x105bc)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  if (piVar3 != (int *)0x0) {
    iVar4 = in_EAX[0x93];
    iVar5 = FUN_0074d700();
    if (in_EAX[0x94] != 0x3ffffffe) {
      in_EAX[0x94] = in_EAX[0x94] + 1;
      *(int *)(iVar4 + 4) = iVar5;
      **(int **)(iVar5 + 4) = iVar5;
      (**(code **)(*in_EAX + 0x70))();
      FUN_006c9580();
      if (piVar3[0x43] != 0) {
        FUN_004026e0(piVar3[0x43],0,0xffffffff);
        FUN_006c9150();
      }
      (**(code **)(*piVar3 + 0xd0))();
      iVar4 = 0;
      if (piVar7 != piVar1) {
        iVar5 = 0;
        do {
          piVar2 = (int *)piVar7[2];
          iVar6 = iVar5 * 0xf0 - piVar2[2];
          piVar2[2] = piVar2[2] + iVar6;
          piVar2[4] = piVar2[4] + iVar6;
          iVar5 = (iVar4 + iVar5 * -5) * 0x5a - piVar2[3];
          piVar2[3] = piVar2[3] + iVar5;
          piVar2[5] = piVar2[5] + iVar5;
          FUN_00746f70();
          (**(code **)(*piVar2 + 200))();
          piVar7 = (int *)*piVar7;
          iVar4 = iVar4 + 1;
          iVar5 = iVar4 / 5;
        } while (piVar7 != piVar1);
      }
      return piVar3;
    }
                    /* WARNING: Subroutine does not return */
    FUN_0087db30();
  }
  return (int *)0x0;
}

