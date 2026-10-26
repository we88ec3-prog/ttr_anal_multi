
void FUN_0079a920(int *param_1,int *param_2,int *param_3,int param_4)

{
  int *piVar1;
  float *pfVar2;
  int iVar3;
  int *piVar4;
  undefined8 local_2c;
  undefined1 auStack_18 [20];
  
  piVar1 = (int *)FUN_00891268(0x50);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)IS3D::CBoundBox::vftable;
    piVar4 = piVar1;
    for (iVar3 = 7; piVar4 = piVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar4 = *param_2;
      param_2 = param_2 + 1;
    }
    piVar4 = piVar1 + 8;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar4 = *param_3;
      param_3 = param_3 + 1;
      piVar4 = piVar4 + 1;
    }
    piVar1[0x13] = param_4;
  }
  local_2c = (double)CONCAT44(local_2c._4_4_,piVar1);
  pfVar2 = (float *)(**(code **)(*piVar1 + 4))((int)&local_2c + 4);
  iVar3 = *param_1;
  piVar1 = *(int **)param_1[10];
  local_2c = (double)-(*(float *)(iVar3 + 0xb8) * pfVar2[2] +
                       *(float *)(iVar3 + 0xa0) * *pfVar2 + *(float *)(iVar3 + 0xac) * pfVar2[1] +
                      *(float *)(iVar3 + 0xc4));
  if (piVar1 != (int *)param_1[10]) {
    do {
      pfVar2 = (float *)(**(code **)(*(int *)piVar1[2] + 4))(auStack_18);
      iVar3 = *param_1;
      if (-(*(float *)(iVar3 + 0xb8) * pfVar2[2] +
            *(float *)(iVar3 + 0xa0) * *pfVar2 + *(float *)(iVar3 + 0xac) * pfVar2[1] +
           *(float *)(iVar3 + 0xc4)) < (float)local_2c) {
        iVar3 = FUN_0074d700(piVar1,piVar1[1],&stack0xffffffd0);
        goto LAB_0079aa20;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)param_1[10]);
  }
  piVar1 = (int *)param_1[10];
  iVar3 = FUN_0074d700(piVar1,piVar1[1],&stack0xffffffd0);
LAB_0079aa20:
  if (param_1[0xb] == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  param_1[0xb] = param_1[0xb] + 1;
  piVar1[1] = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}

