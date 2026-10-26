
/* WARNING: Removing unreachable block (ram,0x00890928) */
/* Library Function - Single Match
    __Stollx
   
   Library: Visual Studio 2010 Release */

int __Stollx(byte *param_1,int *param_2,undefined4 param_3,undefined4 *param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int *piVar4;
  byte *pbVar5;
  ulonglong uVar6;
  
  pbVar2 = param_1;
  piVar4 = param_2;
  if (param_2 == (int *)0x0) {
    piVar4 = (int *)&param_1;
  }
  bVar1 = *param_1;
  pbVar5 = param_1;
  while (iVar3 = _isspace((uint)bVar1), iVar3 != 0) {
    pbVar5 = pbVar5 + 1;
    bVar1 = *pbVar5;
  }
  bVar1 = *pbVar5;
  if ((bVar1 == 0x2d) || (bVar1 == 0x2b)) {
    param_2 = (int *)CONCAT13(bVar1,param_2._0_3_);
    pbVar5 = pbVar5 + 1;
  }
  else {
    param_2 = (int *)CONCAT13(0x2b,param_2._0_3_);
  }
  uVar6 = __Stoullx(pbVar5,piVar4,param_3,param_4);
  if (pbVar5 == (byte *)*piVar4) {
    *piVar4 = (int)pbVar2;
  }
  if (((pbVar2 != (byte *)*piVar4) || (uVar6 == 0)) &&
     ((param_2._3_1_ != '+' || (uVar6 < 0x8000000000000000)))) {
    if (param_2._3_1_ != '-') {
      return (int)uVar6;
    }
    if (uVar6 < 0x8000000000000001) {
      return -(int)uVar6;
    }
  }
  piVar4 = __errno();
  *piVar4 = 0x22;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 1;
  }
  if (param_2._3_1_ == '-') {
    iVar3 = 0;
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}

