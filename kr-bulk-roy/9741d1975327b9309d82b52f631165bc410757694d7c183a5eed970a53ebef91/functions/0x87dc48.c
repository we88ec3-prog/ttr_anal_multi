
/* Library Function - Single Match
    __Stolx
   
   Library: Visual Studio 2010 Release */

uint __Stolx(byte *param_1,int *param_2,undefined4 param_3,undefined4 *param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  byte *pbVar6;
  
  pbVar2 = param_1;
  piVar5 = param_2;
  if (param_2 == (int *)0x0) {
    piVar5 = (int *)&param_1;
  }
  bVar1 = *param_1;
  pbVar6 = param_1;
  while (iVar3 = _isspace((uint)bVar1), iVar3 != 0) {
    pbVar6 = pbVar6 + 1;
    bVar1 = *pbVar6;
  }
  bVar1 = *pbVar6;
  if ((bVar1 == 0x2d) || (bVar1 == 0x2b)) {
    param_2 = (int *)CONCAT13(bVar1,param_2._0_3_);
    pbVar6 = pbVar6 + 1;
  }
  else {
    param_2 = (int *)CONCAT13(0x2b,param_2._0_3_);
  }
  uVar4 = __Stoulx(pbVar6,piVar5,param_3,param_4);
  if (pbVar6 == (byte *)*piVar5) {
    *piVar5 = (int)pbVar2;
  }
  if (((pbVar2 != (byte *)*piVar5) || (uVar4 == 0)) &&
     ((param_2._3_1_ != '+' || (uVar4 < 0x80000000)))) {
    if (param_2._3_1_ != '-') {
      return uVar4;
    }
    if (uVar4 < 0x80000001) {
      return -uVar4;
    }
  }
  piVar5 = __errno();
  *piVar5 = 0x22;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 1;
  }
  return (param_2._3_1_ == '-') + 0x7fffffff;
}

