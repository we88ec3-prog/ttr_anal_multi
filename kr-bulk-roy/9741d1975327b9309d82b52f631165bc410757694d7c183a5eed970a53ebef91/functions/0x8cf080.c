
void FUN_008cf080(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  int in_EAX;
  int iVar5;
  int *in_ECX;
  int iVar6;
  int *piVar7;
  
  iVar1 = *(int *)(in_EAX * 0xcc + 200 + in_ECX[6]);
  iVar6 = *in_ECX;
  if (iVar6 != 0) {
    piVar7 = (int *)(in_ECX[2] + 0x24);
    do {
      piVar2 = (int *)piVar7[-3];
      if (piVar2 != (int *)0x0) {
        if ((piVar7[-5] & 0x200U) == 0) {
          if ((piVar7[-5] & 0x400U) == 0) {
            iVar5 = piVar7[-2] - *piVar2;
            if (iVar5 < 1) {
              lVar4 = (longlong)iVar5 * (longlong)iVar1;
              lVar4 = lVar4 + (ulonglong)((int)(lVar4 >> 0x3f) + 0x8000);
              iVar5 = piVar2[2] + ((uint)lVar4 >> 0x10) + (int)((ulonglong)lVar4 >> 0x20) * 0x10000;
            }
            else {
              iVar3 = piVar2[1];
              if (iVar3 <= iVar5) {
                lVar4 = (longlong)(iVar5 - iVar3) * (longlong)iVar1;
                lVar4 = lVar4 + (ulonglong)((int)(lVar4 >> 0x3f) + 0x8000);
                *piVar7 = piVar2[3] + piVar2[2] +
                          ((uint)lVar4 >> 0x10) + (int)((ulonglong)lVar4 >> 0x20) * 0x10000;
                goto LAB_008cf169;
              }
              iVar5 = FUN_008b7dc0(iVar5,piVar2[3],iVar3);
              iVar5 = iVar5 + piVar2[2];
            }
            *piVar7 = iVar5;
          }
          else {
            *piVar7 = piVar2[3] + piVar2[2];
          }
        }
        else {
          *piVar7 = piVar2[2];
        }
LAB_008cf169:
        piVar7[-5] = piVar7[-5] | 0x20;
      }
      piVar7 = piVar7 + 10;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  return;
}

