# QG训练营前端组第三周周记

2020年4月14日

## 生活随记

+ 这周终于完成了一些学习上的flag，完成了高数，电路的复习，高数真的复习好久才基本掌握了，写了一天的高数作业……挺秃然的，感觉这学期的难度明显上升了，大雾还是雾里看花，还是没有找到时间看一遍，接下去要找时间做大雾了

+ 韩国语也马上要考试，也得找一天复习啊，不过还是很虚，毕竟是全新的线上考试环节，不知道会出成咋样，

## 一周总结

+ 高数复习了两章，还有好多的网上作业，最终都写完了，电路的书也到了，学起来应该会好些了。
+ 了解了一点点css3的轮播图，简单地实现了三张照片轮播，HTML5的语义化挺好的,aside,main，用它们实现了侧边栏+主页内容布局;
+ 多学习，多百度

## 存在问题

+ 这周拖拖拉拉的，大组作业迟交，小组作业还没看懂，渐渐吃力了，这周又是没有学习基础，到现在就吃力了，还是保持学到就是赚到的思想，但是速度也不能太慢，努力拿出时间看懂，哈哈有点羞愧，好多次拖作业了;上一周的目标到了星期二才完成大部分。
  
+ required

    ```html
    <input type="text" required oninvalid="setCustomValidity('不能为空')" οninput="setCustomValidity('')">
    ```

    想自定义非法输入的语段，用以上代码。
    但是在实践中，如果有一次格式非法，然后如上提示"请输入合法的1-18位...之后，所有合法的输入然后submit会提示非法输入。

+ fixed定位后的导航栏在定位标签的时候会被导航栏覆盖一些导致显示内容不全，用下面方法掩盖a标签定位误差

```css
padding-top = 导航栏px;
margin-top = -导航栏px;
```

## 下周规划

 把js部分学习起来，大雾搞起来，布局的多了解一些，不要一拉伸就崩，注意css,html缩进问题！别粗心！
