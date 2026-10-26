
void FUN_0079af30(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  float *pfVar2;
  int iVar3;
  int *piVar4;
  int *unaff_EDI;
  int *piStack_30;
  undefined8 local_2c;
  undefined1 auStack_18 [20];
  
  piVar1 = (int *)FUN_00891268(0x20);
  piVar4 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    *piVar1 = (int)IS3D::CCircle::vftable;
    piVar1[1] = param_1;
    piVar1[2] = param_2;
    piVar1[4] = param_4;
    piVar1[7] = 0;
    piVar1[3] = param_3;
    piVar1[5] = param_5;
    piVar1[6] = 0x28;
    piVar4 = piVar1;
  }
  local_2c = (double)CONCAT44(local_2c._4_4_,piVar4);
  pfVar2 = (float *)(**(code **)(*piVar4 + 4))((int)&local_2c + 4);
  iVar3 = *unaff_EDI;
  piVar1 = *(int **)unaff_EDI[10];
  local_2c = (double)-(*(float *)(iVar3 + 0xb8) * pfVar2[2] +
                       *(float *)(iVar3 + 0xa0) * *pfVar2 + *(float *)(iVar3 + 0xac) * pfVar2[1] +
                      *(float *)(iVar3 + 0xc4));
  if (piVar1 != (int *)unaff_EDI[10]) {
    do {
      pfVar2 = (float *)(**(code **)(*(int *)piVar1[2] + 4))(auStack_18);
      iVar3 = *unaff_EDI;
      if (-(*(float *)(iVar3 + 0xb8) * pfVar2[2] +
            *(float *)(iVar3 + 0xa0) * *pfVar2 + *(float *)(iVar3 + 0xac) * pfVar2[1] +
           *(float *)(iVar3 + 0xc4)) < (float)local_2c) {
        iVar3 = FUN_0074d700(piVar1,piVar1[1],&piStack_30);
        goto LAB_0079b032;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)unaff_EDI[10]);
  }
  piVar1 = (int *)unaff_EDI[10];
  piStack_30 = piVar4;
  iVar3 = FUN_0074d700(piVar1,piVar1[1],&piStack_30);
LAB_0079b032:
  if (unaff_EDI[0xb] == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  unaff_EDI[0xb] = unaff_EDI[0xb] + 1;
  piVar1[1] = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}

