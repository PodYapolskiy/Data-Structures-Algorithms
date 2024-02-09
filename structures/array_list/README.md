# Array List

### Idea

The storage that recalls massive but that can be expanded dynamically underneath. The main focus is access to the elements that is O(1).

### Data Structures

- Array

### Complexity

<table>
    <thead>
        <tr>
            <th>Operation</th>
            <th>Time</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td align="center"><b>size()</b></td>
            <td align="center"><b>O(1)</b></td>
        </tr>
        <tr>
            <td align="center"><b>isEmpty()</b></td>
            <td align="center"><b>O(1)</b></td>
        </tr>
        <tr>
            <td align="center"><b>get(i)</b></td>
            <td align="center"><b>O(1)</b></td>
        </tr>
        <tr>
            <td align="center"><b>set(i, e)</b></td>
            <td align="center"><b>O(1)</b></td>
        </tr>
        <tr>
            <td align="center"><b>add(i, e)</b></td>
            <td align="center"><b>O(n)*</b></td>
        </tr>
        <tr>
            <td align="center"><b>remove(i)</b></td>
            <td align="center"><b>O(n)</b></td>
        </tr>
        <tr>
            <td align="center"><b>addFirst()</b></td>
            <td align="center"><b>O(n)</b></td>
        </tr>
        <tr>
            <td align="center"><b>addLast()</b></td>
            <td align="center"><b>O(1)*</b></td>
        </tr>
        <tr>
            <td align="center"><b>removeFirst()</b></td>
            <td align="center"><b>O(n)</b></td>
        </tr>
        <tr>
            <td align="center"><b>removeLast()</b></td>
            <td align="center"><b>O(1)</b></td>
        </tr>
    </tbody>
</table>

\* - amortised
